"use strict";

var NOT_FOUND = "===";
var letters = ["A", "C", "T", "G"];

function countLetters (genom) {
    var count = {};
    for (var i = 0; i < letters.length; i++) {
        count[letters[i]] = 0;
    }
    for (i = 0; i < genom.length; i++) {
        if (letters.indexOf(genom[i]) !== -1) {
            count[genom[i]]++;        
        }
    }
    return count;
}

function reconstruct (genom) {
    if (genom.length % 4 !== 0) {
        return NOT_FOUND;
    }
    var count = countLetters(genom);
    var desiredCount = Math.round(genom.length / 4);
    for (var i = 0; i < letters.length; i++) {
        if (count[letters[i]] > desiredCount) {
            return NOT_FOUND;
        }    
    }
    var result = "";
    for (i = 0; i < genom.length; i++) {
        if (letters.indexOf(genom[i]) === -1) {
            var curLetter = letters.filter(function (s) {
                return count[s] < desiredCount;
            })[0];
            result += curLetter;
            count[curLetter]++;
        } else {
            result += genom[i];
        }    
    }
    return result;
}

var n = parseInt(readline());
var s = readline();
print(reconstruct(s));