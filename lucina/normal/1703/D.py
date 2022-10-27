import sys
input = sys.stdin.readline
 
for _ in range(int(input())):
    n = int(input().strip())
    d = dict()
    s = []
    for i in range(n):
        s.append(input().strip())
        d[s[-1]] = 1 if s[-1] not in d else d[s[-1]] + 1
    ans = ""
    for i in range(n):
        d[s[i]] -= 1
        ok = False
        for j in range(len(s[i])):
            ss = s[i]
            if ss[:j] in d and ss[j:] in d:
                ok = True
                break
            if (ss[:j] == ss[j:] and ss[:j] in d and d[ss[:j]] >= 2):
                ok = True
                break
        d[s[i]] += 1
        ans += "1" if ok else "0"
    sys.stdout.write(ans + '\n')