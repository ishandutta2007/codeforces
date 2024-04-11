namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        return (
            [ControlledRotation((0, new Int[0]), PauliY, 0)],
            ([3.141592653589793], 0.0));
    }
}