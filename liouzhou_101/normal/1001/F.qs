namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Check (qs : Qubit[], bits : Bool[]) : Bool
    {
        body
        {
            let n = Length(qs);
            for (i in 0..n-1)
            {
                if (BoolFromResult(M(qs[i])) != bits[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            if (Check(qs, bits0))
            {
                return 0;
            }
            elif (Check(qs, bits1))
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}