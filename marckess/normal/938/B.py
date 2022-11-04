from sys import stdout, stdin

n = int(stdin.readline())
l = [1]
l += [int(i) for i in stdin.readline().split()]
l.append(1000000)

res = 1000000
for i in range(1, len(l)):
	if (res > max(l[i-1] - l[0], l[-1] - l[i])):
		res = max(l[i-1] - l[0], l[-1] - l[i])

stdout.write(str(res) + '\n')