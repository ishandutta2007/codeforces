for t in range(input()):
    if t: raw_input()
    A = [raw_input() for i in range(8)]
    sy = sx = 0
    for i in range(8):
        for j in range(8):
            if A[i][j] == 'K':
                ey,ex = sy,sx
                sy,sx = i,j
    print 'YES' if (sy-ey)%4 == 0 and (sx-ex)%4 == 0 else 'NO'