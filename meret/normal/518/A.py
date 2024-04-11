def lex_next(s):
    for i in range(len(s)-1, -1, -1):
           if s[i] < 'z':
                return s[:i]+chr(ord(s[i])+1)+'a'*(len(s)-i-1)

s = raw_input()
t = raw_input()
candidate = lex_next(s)
if t == candidate:
    print 'No such string'
else:
    print candidate