namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable res=0;
            Ry(PI()/4.0,q);
            if(M(q)==One)
            {
                set res=1;
            }
            return res;
        }
    }
}