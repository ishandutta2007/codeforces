namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable n=Length(qs);
            mutable p1=1;
            mutable p2=1;
            for (i in 0..n-1) {
                let p=M(qs[i]);
                if ((p==One)!=bits0[i]) {
                    set p1 = 0;
                }
                if ((p==One)!=bits1[i]) {
                    set p2 = 0;
                }
            }
            if (p1==1) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}