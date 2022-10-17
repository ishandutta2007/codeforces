import string

def solve(s):
    used = set()
    key = s[0]
    used.add(s[0])
    pos = 0
    for c in s[1:]:
        if pos > 0 and key[pos-1] == c:
            pos -= 1
        elif pos+1 < len(key) and key[pos+1] == c:
            pos += 1
        elif c in used:
            return False
        elif pos == 0:
            key = c + key
            used.add(c)
        elif pos+1 == len(key):
            key += c
            used.add(c)
            pos += 1
        else:
            return False
    for c in string.lowercase:
        if c not in used:
            key += c
    return key

n = int(raw_input())
for i in range(n):
    s = solve(raw_input())
    if not s:
        print "NO"
    else:
        print "YES"
        print s