namespace Solution {
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Extensions.Diagnostics;

//	operation F(b : Bool[][], i1 : Int, i2 : Int) : Int {
//		mutable idx = -1;
//		repeat {
//			set idx = idx + 1;
//		} until (b[i1][idx] != b[i2][idx]) fixup {}
//		return idx;
//	}

	// Prepares two superpositions in the qubits, while skipping the state of index 'skip'
	// and it reads the desired state from b[i] and b[j]
	operation PrepareTwo(qs : Qubit[], b : Bool[][], i : Int, j : Int, skip : Int) : Unit {
		body (...) {
			let n = Length(qs);
			mutable idx = -1;
			repeat {
				set idx = idx + 1;
			} until (idx != skip && b[i][idx] != b[j][idx]) fixup {}

			H(qs[idx]);
			for (k in 0..n-1) {
				if (k != skip && k != idx && b[i][k] != b[j][k]) {
					CNOT(qs[idx], qs[k]);
				}
			}
			for (k in 0..n-1) {
				if (k != skip && b[i][k]) { X(qs[k]); }
			}
		}

		controlled auto;
	}

	operation NrOn(b : Bool[][], i : Int) : Int {
		body (...) {
			mutable n = 0;
			if (b[0][i]) { set n=n+1; }
			if (b[1][i]) { set n=n+1; }
			if (b[2][i]) { set n=n+1; }
			if (b[3][i]) { set n=n+1; }
			return n;
		}
	}

	// returns the index j such that b[j][i] != b[k][i] iff k != j.
	operation UniqueOne(b : Bool[][], i : Int) : Int {
		    if (b[0][i] != b[1][i] && b[0][i] != b[2][i] && b[0][i] != b[3][i]) {
			return 0;
		} elif (b[1][i] != b[0][i] && b[1][i] != b[2][i] && b[1][i] != b[3][i]) {
			return 1;
		} elif (b[2][i] != b[0][i] && b[2][i] != b[1][i] && b[2][i] != b[3][i]) {
			return 2;
		} elif (b[3][i] != b[0][i] && b[3][i] != b[1][i] && b[3][i] != b[2][i]) {
			return 3;
		} else {
			return -1;
		}
	}

	operation Solve(qs : Qubit[], b : Bool[][]) : Unit {
		body (...) {
			let n = Length(qs);

			mutable idx = -1;
			mutable on1 = -1; mutable on2 = -1;
			mutable off1 = -1; mutable off2 = -1;
			mutable curidx = 0;
			repeat {
				let N = NrOn(b, curidx);
				if (N == 2) {
					set idx = curidx;
					if (b[0][idx]) { set on1=0; } else { set off1=0; }

					if (b[1][idx]) { if (on1<0) { set on1=1; } else { set on2=1; } }
					else {        if (off1<0) { set off1=1; } else { set off2=1; } }
					if (b[2][idx]) { if (on1<0) { set on1=2; } else { set on2=2; } }
					else {        if (off1<0) { set off1=2; } else { set off2=2; } }
					if (b[3][idx]) { if (on1<0) { set on1=3; } else { set on2=3; } }
					else {        if (off1<0) { set off1=3; } else { set off2=3; } }
				}
				set curidx = curidx+1;
			} until (curidx >= n || N == 2) fixup {}
			// Message($"Indices: {idx}, {curidx}");

			if (idx >= 0) {
				// Message($"Trying the two state trick");
				// prepare two states independently.
				H(qs[idx]);
				(Controlled PrepareTwo)([ qs[idx] ], (qs, b, on1, on2, idx));
				X(qs[idx]);
				(Controlled PrepareTwo)([ qs[idx] ], (qs, b, off1, off2, idx));
				X(qs[idx]);
			} else {

				// at every index there are either 0, 1, 3 or 4 bits on.
				// 0 / 4: X(qs[idx]) or ignore.

//				let i01 = F(b, 0, 1);
//				let i02 = F(b, 0, 2);
//				let i03 = F(b, 0, 3);
//				let i12 = F(b, 1, 2);
//				let i13 = F(b, 1, 3);
//				let i23 = F(b, 2, 3);
//
//				H(qs[i01]);
//				for (j in 0..n-1) {
//					if (j != i01 && b[1][j] != b[0][j]) {
//						CNOT(qs[i01], qs[j]);
//					}
//				}
//				
//				// psi_1 (xor psi_0) is ready.
//
//				// now construct psi_2 from psi_1
//				if (i12 != i01) {
//					// easy version.
//					if (b[1][i12] != b[0][i01]) {
//						X(qs[i12]);
//					}
//					(Controlled H)([ qs[i01] ], qs[i12]);
//					for (j in 0..n-1) {
//						if (j != i01 && j != i12 && b[2][j] != b[1][j]) {
//							(Controlled H)([ qs[i01], qs[i12] ], qs[j]);
//						}
//					}
//
//					if (b[1][i12] != b[0][i01]) {
//						X(qs[i12]);
//					}
//				}

				// walk through, check for #on = 1 or #on = 3
				mutable lastOn = [ -1, -1, -1, -1 ];
				mutable fon = -1;
				mutable son = -1;
				mutable ton = -1;
				mutable lon = -1;

//				for (j in 0..n-1) {
//					let N = NrOn(b, j);
//					if (N == 1 || N == 3) {
//						let i = UniqueOne(b, j);
//						// flip a bit.
//						if (lastOn[i] >= 0) {
//							// do by condition
//							CNOT(qs[lastOn[i]], qs[j]);
//						} else {
//							if (fon < 0) {
//								H(qs[j]);
//								set fon = j;
//							} elif (son < 0) {
//								(Controlled H)([ qs[fon] ], qs[j]);
//								CNOT(qs[j], qs[fon]);
//								set son = j;
//							} elif (ton < 0) {
//								let regs = [ qs[fon], qs[son] ];
//
//								MultiX(regs); (Controlled H)(regs, qs[j]); MultiX(regs);
//								set ton = j;
//							} else {
//								let regs = [ qs[fon], qs[son], qs[ton] ];
//
//								MultiX(regs); (Controlled X)(regs, qs[j]); MultiX(regs);
//							}
//							set lastOn[i] = j;
//						}
//					}
//				}

				for (j in 0..n-1) {
					let N = NrOn(b, j);
					if (N == 1 || N == 3) {
						let i = UniqueOne(b, j);
						// flip a bit.
						if (lastOn[i] < 0) {
							if (fon < 0) {
								H(qs[j]);
								set fon = j;
							} elif (son < 0) {
								(Controlled H)([ qs[fon] ], qs[j]);
								CNOT(qs[j], qs[fon]);
								set son = j;
							} elif (ton < 0) {
								let regs = [ qs[fon], qs[son] ];

								MultiX(regs); (Controlled H)(regs, qs[j]); MultiX(regs);
								set ton = j;
							} else {
								let regs = [ qs[fon], qs[son], qs[ton] ];

								MultiX(regs); (Controlled X)(regs, qs[j]); MultiX(regs);
								set lon = j;
							}
							set lastOn[i] = j;
						}
					}
				}

				for (j in 0..n-1) {
					let N = NrOn(b, j);
					if (N == 1 || N == 3) {
						let i = UniqueOne(b, j);
						// flip a bit.
						if (lastOn[i] >= 0 && j != fon && j != son && j != ton && j != lon) {
							CNOT(qs[lastOn[i]], qs[j]);
						}
					}
				}

				// Message($"Indices are resp. {fon}, {son}, {ton}");

				for (j in 0..n-1) {
					if (NrOn(b, j) >= 3) {
						X(qs[j]);
					}
				}
			}
		}
	}

	operation HelloQ () : Unit {
		// Message("Hello quantum world!");
		using (qs = Qubit[6]) {
//			Solve(qs, [
//				[false,  true, false, false],
//				[false,  true, false,  true],
//				[ true,  true, false,  true],
//				[false, false,  true,  true]
//			]);
			Solve(qs, [
				[  true,  true, false, false, false,  true ],
				[ false, false,  true, false,  true, false ],
				[ false, false, false,  true, false, false ],
				[ false, false, false, false, false, false ]
			]);
			// DumpMachine();
			ResetAll(qs);
		}
	}
}