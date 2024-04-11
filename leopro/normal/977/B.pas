var
  a: array ['A'..'Z','A'..'Z'] of Int32;
  i, n, max: Int32;
  s: string;
  b, c: Char;

begin
  ReadLn(n);
  ReadLn(s);
  For b := 'A' to 'Z' do
  begin
    For c := 'A' to 'Z' do
    begin
      a[b, c] := 0;
    end;
  end;
  For i := 1 to n-1 do
  begin
    inc(a[s[i], s[i+1]]);
  end;
  max := -1;
  For b := 'A' to 'Z' do
  begin
    For c := 'A' to 'Z' do
    begin
      If a[b, c] > max then max := a[b, c];
    end;
  end;
  For b := 'A' to 'Z' do
  begin
    For c := 'A' to 'Z' do
    begin
      If a[b, c] = max then
      begin
        WriteLn(b, c);
        readln;
        Exit;
      end;
    end;
  end;
end.