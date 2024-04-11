n = int(input())

arr = list(map(int, input().split()))
arr1 = arr[:]

#print(arr)
arr.sort()
#print(arr)

l = -1
r = -1

#print(len(arr))
#print(len(arr1))

for i in range(n):
	if (arr[i] != arr1[i]):
		r = i

for i in range(n - 1, -1, -1):
	if (arr[i] != arr1[i]):
		l = i

if (l == -1 and r == -1):
	print("yes\n1 1")
	exit()

#print("l equals", l)
#print("r equals", r)

arr1[l:r + 1] = arr1[l:r + 1][::-1]

#print(arr1)

for i in range(n):
	if (arr[i] != arr1[i]):
		print("no")
		exit()

print("yes")
print(l + 1, r + 1);