namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
		using (x = Qubit()) {
			repeat{
				H(qs[0]);
				H(qs[1]);
				CCNOT(qs[0],qs[1],x);
				let mx = M(x);
			}until(mx == Zero)
			fixup{
				ResetAll([qs[0],qs[1],x]);
			}
		}
    }
}