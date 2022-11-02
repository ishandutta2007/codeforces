import sys
import string
K = input()
S = raw_input()
cnt = {}; ans = ''
for c in string.lowercase: cnt[c] = 0
for c in S: cnt[c] += 1
for c in string.lowercase:
    if cnt[c]%K != 0:
        print -1
        sys.exit()
    ans += c*(cnt[c]/K)
print ans*K