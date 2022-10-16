#!/usr/bin/env python3

import sys

N = int(sys.stdin.readline().strip())
S = sys.stdin.readline().strip() + '?'

last = ''
cnt = 0

for ch in S:
    if ch != last:
        if cnt != 0:
            if last in 'aiuy': cnt = 1
            if last in 'eo' and cnt > 2: cnt = 1
            print(last * cnt, end='')
        last = ch
        cnt = 0

    cnt += 1

print()