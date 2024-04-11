s=raw_input()
s='a'+s
r=0
for i in range(1,len(s)):
  r+=min(abs(ord(s[i-1])-ord(s[i])), 26-abs(ord(s[i-1])-ord(s[i])))
print r