vectors = [(0, 0), (1, -1), (1, 0), (1, 1), (2, 0)]

N = int(input())
board = [list(input()) for row_id in range(N)]

for row in range(N - 2):
    for col in range(1, N - 1):
        can_place = all(board[row + dr][col + dc] == '.' for (dr, dc) in vectors)
        if can_place:
            for (dr, dc) in vectors:
                board[row + dr][col + dc] = '#'

has_dots = any(row.count('.') for row in board)
print('NO' if has_dots else 'YES')