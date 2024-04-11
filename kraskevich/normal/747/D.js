"use strict";

function cmp (a, b) {
    if (a < b)
        return -1;
    if (a === b)
        return 0;
    return 1;
}

function solve(n, k, ts) {
    var negative = [];
    for (var i = 0; i < ts.length; i++)
        if (ts[i] < 0)
            negative.push(i);
    if (negative.length > k)
        return -1;
    if (negative.length === 0)
        return 0;
    k -= negative.length;
    var diffs = [];
    for (i = 1; i < negative.length; i++)
        if (negative[i] !== negative[i - 1] + 1)
            diffs.push(negative[i] - negative[i - 1] - 1);
    diffs.sort(cmp);
    i = 0;
    var segms = diffs.length + 1;
    while (i < diffs.length && diffs[i] <= k) {
        k -= diffs[i];
        i++;
        segms--;
    }
    var res = 2 * segms;
    if (k >= n - negative[negative.length - 1] - 1)
        res--;
    return res;  
}

var line = readline().split(' ');
var n = parseInt(line[0]);
var k = parseInt(line[1]);
var ts = readline().split(' ').map(function(s) { return parseInt(s); });
print(solve(n, k, ts));