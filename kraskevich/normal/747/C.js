"use strict";

var serversReturnedAt = [];
var serversRequiredAt = [];
var isEmpty = [];

var MAX_TIME = 1000 * 1000 + 10;


function init (servers) {
    for (var t = 0; t < 2 * MAX_TIME; t++) {
        serversReturnedAt.push([]);
        serversRequiredAt.push([]);
    }
    for (var i = 0; i < servers; i++) {
        isEmpty.push(true);
    }
}

function obtainFirstServers (servers) {
    var chosen = [];
    for (var i = 0; i < isEmpty.length; i++) {
        if (isEmpty[i] && chosen.length < servers) {
            chosen.push(i);
        }    
    }
    if (chosen.length < servers) {
        return undefined;
    }
    return chosen;
}

function Query (id, servers, duration) {
    this.id = id;
    this.servers = servers;
    this.duration = duration;
}

function add (a, b) {
    return a + b;
}

function solve () {
    var result = {};
    for (var time = 0; time < MAX_TIME; time++) {
        for (var i = 0; i < serversReturnedAt[time].length; i++) {
            isEmpty[serversReturnedAt[time][i]] = true;
        }    
        for (i = 0; i < serversRequiredAt[time].length; i++) {
            var query = serversRequiredAt[time][i];
            var chosen = obtainFirstServers (query.servers);
            if (!chosen) {
                result[query.id] = -1;
            } else {
                result[query.id] = chosen.length + chosen.reduce(add, 0);
                for (var j = 0; j < chosen.length; j++) {
                    isEmpty[chosen[j]] = false;
                    serversReturnedAt[time + query.duration].push(chosen[j]);                
                }
            }
        }
    }
    return result;
}


var line = readline().split(' ');
var servers = parseInt(line[0]);
var queries = parseInt(line[1]);
init(servers);
for (var i = 0; i < queries; i++) {
    line = readline().split(' ');
    var t = parseInt(line[0]);
    var servers = parseInt(line[1]);
    var duration = parseInt(line[2]);
    serversRequiredAt[t].push(new Query(i, servers, duration));    
} 
var result = solve();
for (i = 0; i < queries; i++) {
    print(result[i]);
}