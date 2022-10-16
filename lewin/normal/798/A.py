s = raw_input()

def f(s):
  for i in range(len(s)):
    for x in range(26):
      if ord(s[i])-ord('a') == x:
        continue
      t = s[:i] + chr(x+ord('a')) + s[i+1:]
      if t == t[::-1]:
        print "YES"
        return
  print "NO"

f(s)