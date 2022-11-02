namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Math;

	operation wstate(qs : Qubit[]) : Unit {
		body (...) {
			let n = Length(qs);
			if (n == 1) {
				X(qs[0]);
			} else {
				Ry(2.0 * ArcSin(1.0 / Sqrt(ToDouble(n))), qs[0]);

				X(qs[0]);
				Controlled wstate([ qs[0] ], qs[1 .. n - 1]);
				X(qs[0]);
			}
		}

		adjoint invert;
		controlled distribute;
		controlled adjoint distribute;
	}

	operation Solve(qs : Qubit[]) : Int {
		body (...) {
			R1(4.188790204, qs[1]);
			R1(2.094395102, qs[2]);
			
			// now we either have the w_3-state,
			// or 1/3 (|100+ \omega |010+ \omega^2 |001.
			(Adjoint wstate)(qs);

			if (IsResultZero(M(qs[0])) && IsResultZero(M(qs[1])) && IsResultZero(M(qs[2]))) {
				return 0;
			} else {
				return 1;
			}
		}
	}
}