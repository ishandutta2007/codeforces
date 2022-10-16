s = raw_input()
rev = {
	"o": "o",
	"x": "x",
	"b": "d",
	"p": "q",
	"d": "b",
	"q": "p",
	"v": "v",
	"x": "x",
	"w": "w",
	"H": "H",
	"I": "I",
	"O": "O",
	"X": "X",
	"W": "W",
	"U": "U",
	"T": "T",
	"V": "V",
	"Y": "Y",
	"A": "A",
	"M": "M",
}

t = "".join([rev.get(c, "@") for c in s[::-1]])
print "TAK" if t == s else "NIE"