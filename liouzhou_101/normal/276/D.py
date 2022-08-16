l,r=map(int,raw_input().split())
print 2**max(i+1 if l&1<<i!=r&1<<i else 0 for i in range(60))-1