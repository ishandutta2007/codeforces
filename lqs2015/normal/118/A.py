s = input()
s = s.lower()
res = ''
for i in range(len(s)):
    if s[i] not in 'aeiouy' :
        res += '.'
        res += s[i]
print(res)