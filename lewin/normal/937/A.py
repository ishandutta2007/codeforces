x = int(raw_input())
s = set(map(int, raw_input().split()))
s -= {0}
print len(s)