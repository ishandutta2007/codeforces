namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set(desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if(desired != current){
                X(q1);
            }
        }
    }

    operation Solve (q : Qubit) : Int
    {
        body
        {
            T(q);
            Z(q);
            S(q);
            H(q);
            Y(q);
            
            T(q);
            Z(q);
            S(q);
            H(q);
            Y(q);

            if(M(q) == Zero){
                return 0;
            }
            return 1;
        }
    }
}