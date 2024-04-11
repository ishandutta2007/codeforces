namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (index in 0..Length(qs) - 1)
            {
                if (bits0[index] != bits1[index])
                {
                    let x = M(qs[index]);

                    if (x == One)
                    {
                        if (bits0[index])
                        {
                            return 0;
                        }
                        return 1;
                    }
                    else
                    {
                        if (bits1[index])
                        {
                            return 0;
                        }
                        return 1;
                    }
                }
            }

            return -1;
        }
    }
}