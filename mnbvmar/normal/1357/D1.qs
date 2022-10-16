namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    
    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 0),
            ControlledRotation((0, new Int[0]), PauliZ, 1),
            ControlledRotation((1, new Int[0]), PauliX, 2),
            ControlledRotation((1, new Int[0]), PauliZ, 3),
            ControlledRotation((0, [1]), PauliX, 4),
            ControlledRotation((1, [0]), PauliY, 5),
            ControlledRotation((0, [1]), PauliZ, 6),
            ControlledRotation((1, new Int[0]), PauliX, 7)
        ];
    }

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [1.0]), ClassifierStructure(), ([3.40325,4.10325,0.20325000000000007,2.50325,3.3,2.5,4.0,2.50325], 0.3112));
    }
}