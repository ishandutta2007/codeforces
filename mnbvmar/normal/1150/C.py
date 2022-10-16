N = int(input())
num_ones = input().count('1')
num_twos = N - num_ones

if not num_ones or not num_twos:
    solution = [1] * num_ones + [2] * num_twos
else:
    solution = [2, 1] + [2] * (num_twos - 1) + [1] * (num_ones - 1)

print(*solution)