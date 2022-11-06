n,k = map(int,input().split())
l = list(map(int,input().split()))
w = 0
for i in l:
	if i<= k:
		w+=1
	else:
		w+=2
print(w)