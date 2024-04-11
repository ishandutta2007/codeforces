namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

	operation Solve(qs : Qubit[]) : Unit {
        body (...) {
            Ry(1.2309594173407746, qs[0]);
            X(qs[0]);
            (Controlled H)([ qs[0] ], qs[1]);
            X(qs[0]);
            // now remove |11> and
            // transform it into 00, 01 and 10.
        }

        adjoint invert;
	}
}