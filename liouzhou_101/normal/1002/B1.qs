namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable flag = 0;
            for (i in 0..Length(qs)-1)
            {
                if (M(qs[i]) == One)
                {
                    set flag = 1;
                }
            }
            return flag;
        }
    }

}