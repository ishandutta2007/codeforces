var
  N, ans, i, j: LongInt;
  ball: array [1..100] of LongInt;
  was: Boolean;

begin
  ReadLn(n);
  For i := 1 to N do Read(BALL[i]);
  ReadLn;
  ans := 0;
  For i := 1 to N do
  begin
    was := false;
    For j := 1 to i-1 do
    begin
      If ball[i] = ball[j] then was := true;
    end;
    If (not was) and (ball[i] > 0) then inc(ans);
  end;
  WriteLn(ans);
end.