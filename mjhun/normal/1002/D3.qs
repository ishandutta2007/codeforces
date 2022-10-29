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

    operation Asd(x: Qubit, y: Qubit) : ()
    {
        body 
        {
            CNOT(x,y);
        }
        controlled auto
    }

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            let Qwe=Controlled(X);
            Qwe([x[0];x[1]],y);
            Qwe([x[1];x[2]],y);
            Qwe([x[0];x[2]],y);
        }
    }
}