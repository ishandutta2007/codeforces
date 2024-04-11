import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private static final int[] DX = new int[]{-1, 1, 0, 0};
        private static final int[] DY = new int[]{0, 0, -1, 1};
        private int[][] block;
        private char[][] map;
        private int n;
        private int m;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            map = new char[n][];
            for (int i = 0; i < n; ++i) {
                map[i] = in.next().toCharArray();
            }

            block = new int[n][m];
            int blockCount = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (map[i][j] >= '0' && map[i][j] <= '3' && block[i][j] == 0) {
                        bfs(i, j, ++blockCount);
                    }
                }
            }

            int[][][] dists = new int[blockCount][][];
            for (int i = 1; i <= blockCount; ++i) {
                dists[i - 1] = calcDist(i);
            }

//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                System.err.print(block[i][j] + " ");
//            }
//            System.err.println();
//        }
//
//        System.err.println();

//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                System.err.print(dists[1][i][j] + " ");
//            }
//            System.err.println();
//        }

            int answer = 0;
            if (blockCount == 1) {
                answer = 0;
            } else if (blockCount == 2) {
                answer = Integer.MAX_VALUE / 10;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        answer = Math.min(answer, dists[0][i][j] + dists[1][i][j] - 1);
                    }
                }
            } else {
                answer = Integer.MAX_VALUE / 10;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        answer = Math.min(answer, dists[0][i][j] + dists[1][i][j] + dists[2][i][j] - 2);
                    }
                }

                int[][] blkDist = new int[3][3];
                for (int i = 0; i < 3; ++i) {
                    for (int j = i + 1; j < 3; ++j) {
                        blkDist[i][j] = Integer.MAX_VALUE / 10;
                        for (int x = 0; x < n; ++x) {
                            for (int y = 0; y < m; ++y) {
                                blkDist[i][j] = Math.min(blkDist[i][j], dists[i][x][y] + dists[j][x][y] - 1);
                            }
                        }
                    }
                }

                answer = Math.min(answer, blkDist[0][1] + blkDist[0][2]);
                answer = Math.min(answer, blkDist[0][1] + blkDist[1][2]);
                answer = Math.min(answer, blkDist[0][2] + blkDist[1][2]);
            }

            if (answer >= Integer.MAX_VALUE / 10) {
                answer = -1;
            }

            out.println(answer);
        }

        private int[][] calcDist(int bid) {
            int[][] result = new int[n][m];
            Queue<Integer> queue = new LinkedList<Integer>();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (block[i][j] == bid) {
                        result[i][j] = 0;
                        queue.add((i << 11) + j);
                    } else {
                        result[i][j] = Integer.MAX_VALUE / 10;
                    }
                }
            }

            while (!queue.isEmpty()) {
                int x = queue.peek() >> 11;
                int y = queue.peek() & 2047;
                queue.poll();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + DX[d];
                    int ny = y + DY[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m
                            && map[nx][ny] != '#'
                            && result[nx][ny] > result[x][y] + 1) {
                        result[nx][ny] = result[x][y] + 1;
                        queue.add((nx << 11) + ny);
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (block[i][j] == bid) {
                        result[i][j] = Integer.MAX_VALUE / 10;
                    }
                }
            }

            return result;
        }

        private void bfs(int i, int j, int bid) {
            Queue<Integer> queue = new LinkedList<Integer>();
            queue.add((i << 11) + j);
            block[i][j] = bid;
            while (!queue.isEmpty()) {
                int x = queue.peek() >> 11;
                int y = queue.peek() & 2047;

//            System.err.println("x = " + x + ", y = " + y);
                queue.poll();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + DX[d];
                    int ny = y + DY[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && block[nx][ny] == 0
                            && map[nx][ny] >= '0' && map[nx][ny] <= '3') {
                        block[nx][ny] = bid;
                        queue.add((nx << 11) + ny);
                    }
                }
            }
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}