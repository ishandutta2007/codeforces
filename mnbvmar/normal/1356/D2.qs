namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return (
            [ControlledRotation((0, new Int[0]), PauliY, 0)],
            ([1.0440000000000003], 0.25225));
    }
}