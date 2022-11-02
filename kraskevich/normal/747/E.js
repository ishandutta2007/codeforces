"use strict";

var atLevel = {};

function addForLevel (text, level) {
    if (!(level in atLevel)) {
        atLevel[level] = [];    
    }
    atLevel[level].push(text);
}

function parseComment (tokens, pos, level) {
    var text = tokens[pos++];
    var kids = parseInt(tokens[pos++]);
    addForLevel (text, level);
    var positions = [kids];
    while (true) {
        while (positions.length > 0 && positions[positions.length - 1] === 0)
            positions.pop();
        if (positions.length === 0)
            break;        
        text = tokens[pos++];
        kids = parseInt(tokens[pos++]);
        positions[positions.length - 1]--;
        addForLevel (text, positions.length);
        positions.push(kids)
    }
    return pos;
}

function parseAll (s) {
    var tokens = s.split(',');
    var pos = 0;
    while (pos < tokens.length) 
        pos = parseComment(tokens, pos, 0);
}

var s = readline();
parseAll(s);
var level = 0;
while (level in atLevel) 
    level++;
print(level);
for (var i = 0; i < level; i++)
    print(atLevel[i].join(' '));