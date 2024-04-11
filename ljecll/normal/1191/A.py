n = int(input())

if (n % 4 == 3):
	print(2, 'A')
elif (n % 4 == 2):
	print(1, 'B')
elif (n % 4 == 1):
	print(0, 'A')
else:
	print(1, 'A')