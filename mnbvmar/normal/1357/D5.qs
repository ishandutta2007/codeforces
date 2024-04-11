namespace Solution {
    open Microsoft.Quantum.MachineLearning;
    
    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 4),
            ControlledRotation((0, new Int[0]), PauliZ, 5),
            ControlledRotation((1, new Int[0]), PauliX, 6),
            ControlledRotation((1, new Int[0]), PauliZ, 7),
            ControlledRotation((0, [1]), PauliX, 0),
            ControlledRotation((1, [0]), PauliX, 1),
            ControlledRotation((0, [1]), PauliY, 8),
            ControlledRotation((1, [0]), PauliZ, 9),
            ControlledRotation((1, new Int[0]), PauliZ, 2),
            ControlledRotation((1, new Int[0]), PauliX, 3)
        ];
    }

    operation Solve() : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [0.5]), ClassifierStructure(), (
            [4.062149832531262,1.5315037076212346,0.9570132574670538,4.270932738938197,4.507347549069596,3.8281792921622073,0.3910706692858633,2.148950856068011,2.813375574584845,4.032972463011224],
            0.14744999999999997));
    }
}