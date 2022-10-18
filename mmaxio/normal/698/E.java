import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean isLeap(int year) {
		return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
	}

	static final int[] DAYS = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	static final int PERIOD_DAYS = (400 - 100 + 4 - 1) * 365 + (100 - 4 + 1)
			* 366;
	static final int BASE_YEAR = 1970;

	static final long PERIOD_SECONDS = 24L * 60 * 60 * PERIOD_DAYS;

	void solve() throws IOException {
		int[] day = new int[PERIOD_DAYS];
		int[] month = new int[PERIOD_DAYS];
		int[] dayW = new int[PERIOD_DAYS];
		int[] year = new int[PERIOD_DAYS];

		day[0] = 1;
		month[0] = 1;
		dayW[0] = 4;
		year[0] = 0;

		for (int i = 0; i < PERIOD_DAYS - 1; i++) {
			int realDays = DAYS[month[i] - 1];
			if (month[i] == 2 && isLeap(BASE_YEAR + year[i])) {
				realDays++;
			}
			day[i + 1] = day[i] + 1;
			month[i + 1] = month[i];
			year[i + 1] = year[i];

			if (day[i + 1] > realDays) {
				day[i + 1] = 1;
				month[i + 1]++;
				if (month[i + 1] == 13) {
					month[i + 1] = 1;
					year[i + 1]++;
				}
			}

			dayW[i + 1] = dayW[i] + 1;
			if (dayW[i + 1] == 8) {
				dayW[i + 1] = 1;
			}
		}

		int s = nextInt();
		int m = nextInt();
		int h = nextInt();
		int qDayW = nextInt();
		int qDay = nextInt();
		int qMonth = nextInt();

		int[] nextSMH = new int[86400];
		for (int i = 0; i < 86400; i++) {
			int curH = i / 3600;
			int curM = i % 3600 / 60;
			int curS = i % 60;
			if ((s != -1 && curS != s) || (m != -1 && curM != m)
					|| (h != -1 && curH != h)) {
				nextSMH[i] = -1;
			} else {
				nextSMH[i] = 0;
			}
		}

		int firstSMH = -1;

		for (int i = 86398; i >= 0; i--) {
			if (nextSMH[i] == -1) {
				if (nextSMH[i + 1] != -1) {
					nextSMH[i] = nextSMH[i + 1] + 1;
				}
			} else {
				firstSMH = i;
			}
		}

		for (int i = 86399; i >= 0; i--) {
			if (nextSMH[i] == -1) {
				nextSMH[i] = nextSMH[(i + 1) % 86400] + 1;
			}
		}

		int[] nextDMW = new int[PERIOD_DAYS];
		for (int i = 0; i < PERIOD_DAYS; i++) {
			nextDMW[i] = -1;

			if (qMonth != -1 && qMonth != month[i]) {
				continue;
			}

			if (qDay != -1 && qDayW != -1) {
				if (day[i] != qDay && dayW[i] != qDayW) {
					continue;
				}
			} else {
				if (qDay != -1 && qDay != day[i]) {
					continue;
				}
				if (qDayW != -1 && qDayW != dayW[i]) {
					continue;
				}
			}
			nextDMW[i] = 0;
		}

		for (int i = PERIOD_DAYS - 2; i >= 0; i--) {
			if (nextDMW[i] == -1 && nextDMW[i + 1] != -1) {
				nextDMW[i] = nextDMW[i + 1] + 1;
			}
		}

		for (int i = PERIOD_DAYS - 1; i >= 0; i--) {
			if (nextDMW[i] == -1) {
				nextDMW[i] = nextDMW[(i + 1) % PERIOD_DAYS] + 1;
			}
		}

		int q = nextInt();
		while (q-- > 0) {
			long t = nextLong() + 1;
			long initT = t;

			long full = t / PERIOD_SECONDS;
			t %= PERIOD_SECONDS;

			int days = (int) (t / 86400);
			t %= 86400;

			// int deltaSMH = nextSMH[(int) t];
			// if (deltaSMH == 0) {
			// deltaSMH = 1 + nextSMH[(int) (t + 1) % 86400];
			// }
			//
			// boolean strictNext = t + deltaSMH >= 86400;

			int deltaDMW = nextDMW[days];
			if (deltaDMW == 0) {
				int deltaSMH = nextSMH[(int) t];
				if (deltaSMH + t >= 86400) {
					deltaDMW = 1 + nextDMW[(days + 1) % PERIOD_DAYS];

					long outp = full * PERIOD_SECONDS + (days + deltaDMW)
							* 86400L + firstSMH;
					out.println(outp);
				} else {
					out.println(initT + deltaDMW * 86400L + deltaSMH);
				}
			} else {
				long outp = full * PERIOD_SECONDS + (days + deltaDMW) * 86400L
						+ firstSMH;
				out.println(outp);
			}
		}

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}