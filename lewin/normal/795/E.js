s = readline()
m = +readline()
crem = 0
cpow = 1
for (i = s.length-1; i >= 0; i--) {
	crem = (crem + cpow * (+s[i])) % m
	if (i !== 0) {
	    cpow = cpow * 10 % m
	}
}

ans = crem
for (i = 0; i+1 < s.length; i++) {
	crem = (crem - cpow * (+s[i])) % m
	crem = (crem + m) % m
	crem = (crem * 10) % m
	crem = (crem + (+s[i])) % m
	if (s[i+1] != '0') {
	    if (crem < ans) {
	        ans = crem
	    }
	}
}

print(ans)