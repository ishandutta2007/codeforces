var s: ansistring;
    i: longint;
begin
  readln(s);
  for i := 2 to length(s) do if s[i] = s[i-1] then
  begin
    if not((s[i-1] = 'a') or (s[i+1] = 'a')) then s[i] := 'a'
    else if not((s[i-1] = 'b') or (s[i+1] = 'b')) then s[i] := 'b' else s[i] := 'c';
  end;
  write(s);
end.