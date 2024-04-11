input();A=map(int,raw_input().split())
for n in A:print n*[4,2,4,1][n%4]+1