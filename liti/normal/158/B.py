n = input()
a = [0]*5
for i in map(int,raw_input().split()) : 
    a[i] += 1
print a[4] + a[3] + max(0,a[1] - (a[3] + 2*(a[2]&1)) + 3 ) / 4 + (a[2]+1)/2