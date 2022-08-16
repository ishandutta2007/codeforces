input()
a=[0]*40
for x in map(int,raw_input().split()):a[sum(1 for i in range(40) if x&1<<i)]+=1
print sum(x*(x-1)/2 for x in a)