var isNodeJS = false;
// isNodeJS = !isNodeJS;
var doWork = (readline, print) => {
var readInts = () => {
    return readline().split(" ").map(function(x) { return parseInt(x); });
};
/////////////////////////////////////////////////////////////// BEGIN

var nums = readInts();
var n = nums[0];
var m = nums[1];

var a = readInts();
var b = new Array(n).fill(0);
var result = 0;
a.forEach(c => {
    --c;
    b[c]++;
    var allFilled = true;
    b.forEach(v => {
        if (v == 0) allFilled = false;
    });
    if (allFilled) {
        ++result;
        for (var i = 0; i < n; ++i) {
            b[i]--;
        }
    }
});

print(result + "\n");

/////////////////////////////////////////////////////////////// END OF CODE
};

if (isNodeJS) {
    var stdin = process.stdin;
    var stdout = process.stdout;
    var lines, currentLine = 0;
    stdin.resume();
    stdin.once('data', function(data) {
        data = data.toString().trim();
        lines = data.split("\n");
        var readline = () => {
            return lines[currentLine++];
        };
        doWork(readline, stdout.write.bind(stdout));
    });
} else {
    doWork(readline, print);
}