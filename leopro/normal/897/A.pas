program Project1;

var
  m, i, l, r, j: SmallInt;
  s: string;
  c1, c2: char;

function f(l, r: SmallInt; c1, c2: char; s: string): string;
begin
  For j := l to r do
  If s[j] = c1 then s[j] := c2;
  Result := s;
end;

begin
  Read(m); Readln(m);
  ReadLn(s);
  For i := 1 to m do
  begin
    Read(l); Read(r); Read(c1); Read(c1); Read(c2);
    ReadLn(c2);
    s := f(l, r, c1, c2, s);
  end;
  WriteLn(s);
end.