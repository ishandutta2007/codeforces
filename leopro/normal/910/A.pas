var
  N, d, i, j, Ans, Lily: LongInt;
  Lilies: array [1..100] of Boolean;
  c: Char;
  CanGoToThePoint: array [1..100] of Boolean;
  CanGoPoint: array [1..100, 1..100]  of Boolean;

begin
  Read(N, d);
  ReadLn;
  For i := 1 to N do 
  begin 
    Read(c);
    Lilies[i] := c='1';
  end;
  CanGoToThePoint[1] := True;
  For i := 1 to N do
  begin
    If (Lilies[i]) and (CanGoToThePoint[i]) then 
    begin
      For j := i+1 to i+d do
      begin 
        If Lilies[j] then CanGoPoint[j, i] := True;
        If Lilies[j] then CanGoToThePoint[j] := True;
      end;
    end;
  end;
  Ans := 0;
  Lily := N;
  If not (CanGoToThePoint[N]) then WriteLn(-1) else
  While Lily > 1 do 
  begin
    For i := 1 to N do If CanGoPoint[Lily, i] then 
    begin 
      Lily := i;
      Break;
    end;
    inc(Ans);
    If Lily < 2 then WriteLn(ans);
  end;
end.