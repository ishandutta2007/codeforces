def numcap(s):
    return sum(map(int, map(lambda c : c == c.upper(), s)))

n = int(raw_input())
print max(numcap(s) for s in raw_input().split())