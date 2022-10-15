var n = parseInt(readline());
while (n -- > 0) {
    var str = readline();
    var flag = str.length % 2 == 0;
    for (var i = 0; i < str.length / 2; i++) {
        flag = flag & (str[i] == str[i + str.length / 2]);
    }
    print(flag ? "YES" : "NO");
}