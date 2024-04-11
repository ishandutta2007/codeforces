function findRowsAndColumns (n) {
    var bestA = 1;
    for (var a = 1; a * a <= n; a++)
        if (n % a === 0)
            bestA = a;
    return [bestA, Math.round(n / bestA)]
}

n = parseInt(readline());
results = findRowsAndColumns(n);
print(results[0] + " " + results[1]);