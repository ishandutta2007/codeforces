namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            let m = M(q);
	        if ((sign == 1 && m == One) || (sign == -1 && m == Zero)) {
	    	    X(q);
	        }
	        H(q);
       }
    }
}