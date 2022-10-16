namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    
    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 0)
        ];
    }

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [1.0, 1.0]), ClassifierStructure(), ([0.0], 0.25));
    }
}