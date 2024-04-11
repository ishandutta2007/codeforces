#!/bin/bash

cnt = {}

n = int(input())

tot_sum = 0
tot_cnt = 0
res = 0

for y in input().split():
	y = int(y)
	tot_sum += y
	tot_cnt += 1

	if y in cnt:
		cnt[y] += 1
	else:
		cnt[y] = 1

	tmp_sum = tot_sum
	tmp_cnt = tot_cnt

	for d in range(-1, 2):
		x = y + d
		if x in cnt:
			tmp_sum -= x * cnt[x]
			tmp_cnt -= cnt[x]

	res += tmp_cnt * y - tmp_sum


print(res)