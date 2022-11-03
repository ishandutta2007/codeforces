namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            mutable res=0;
            for(i in 0..Length(x)-1)
            {
                CNOT(x[i],y);
                set res=res+1-b[i];
            }
            if(res%2==1)
            {
                X(y);
            }
        }
    }
}