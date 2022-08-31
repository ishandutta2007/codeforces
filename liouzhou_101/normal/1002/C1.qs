namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(-PI()*0.25, q);
            if (Measure([PauliX], [q]) == Zero)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

}