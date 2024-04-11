var isNodeJS = false;
// isNodeJS = !isNodeJS;
var doWork = (readline, print) => {
var readInts = () => {
    return readline().split(" ").map(function(x) { return parseInt(x); });
};

/////////////////////////////////////////////////////////////// BEGIN

var nums = readInts();
var n = nums[0];
var k = nums[1];

var a = readInts();
var t = readInts();

var always = 0;

t.forEach((_, i) => {
    if (t[i] == 1) {
        always += a[i];
        a[i] = 0;
    }
});

var s = new Array(n).fill(0);

for (var i = 0; i < n; ++i) {
    s[i] = a[i] + (i == 0 ? 0 : s[i - 1]);
}

var best = 0;
for (var i = 0; i < n; ++i) {
    var current = always + s[i] - (i - k >= 0 ? s[i - k] : 0);
    if (best < current) best = current;
}

print(best + "\n");

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