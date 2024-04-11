def solve(s):
    a, b = s.find('1'), s.rfind('1')
    if a == -1:
        return 0
    return s[a:b+1].count('0')

n = int(raw_input())
for i in range(n):
    print solve(raw_input())