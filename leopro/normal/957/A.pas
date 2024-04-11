var
  i, N: Int32;
  Colors: array [1..100] of Char;
  ans1, ans2: Boolean;

begin
  ReadLn(N);
  For i := 1 to N do Read(Colors[i]);
  ReadLn;
  ans1 := False;
  ans2 := False;
  If (Colors[1] = '?') or (Colors[N] = '?') then ans1 := True;
  For i := 2 to N-1 do
  begin
    If Colors[i] = '?' then
    begin
      If Colors[i+1] = '?' then ans1 := True;
      If Colors[i-1] = '?' then ans1 := True;
      If Colors[i-1] = Colors[i+1] then ans1 := True;
    end else
    begin
      If Colors[i+1] = Colors[i] then ans2 := True;
      If Colors[i-1] = Colors[i] then ans2 := True;
    end;
  end;
  If ans2 = False then
  begin
    If ans1 = True then
    begin
      WriteLn('Yes');
      Exit;
    end;
  end;
  WriteLn('No');
end.