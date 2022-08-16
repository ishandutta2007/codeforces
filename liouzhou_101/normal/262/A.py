k=int(raw_input().split()[1])
print sum(s.count('4')+s.count('7')<=k for s in raw_input().split())