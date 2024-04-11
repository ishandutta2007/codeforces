uses
Math;

var
  n, w, h, k, len, minval, maxval, i, j: Int32;
  s: string;
  letters, stars, quests, delete_, create_: Int32;


begin
  ReadLn(s);
  ReadLn(k);
  len := length(s);
  letters:=0;
  stars:=0;
  quests:=0;
  for i := 1 to len do
  begin
    case s[i] of
      '*': stars += 1;
      '?': quests += 1;
      else letters += 1;
    end;
  end;
  minval := max(0, letters - quests - stars);
  if stars = 0 then maxval := letters else maxval := 200000;
  if (k < minval) or (k > maxval) then
  begin
    WriteLn('Impossible');
    Exit;
  end;
  if k = letters then
  begin
    for i := 1 to len do
      if s[i] <> '*' then
        if s[i] <> '?' then
          Write(s[i]);

    WriteLn;
    Exit;
  end;
  if k < letters then
  begin
    for i := 1 to len do
    begin
      if (s[i] <> '*') and(s[i] <> '?') then
      begin
          if ((s[i+1] = '*') or (s[i+1] = '?')) and (k < letters) then
          begin
            letters -= 1;
          end else
          begin
            Write(s[i]);
            letters -= 1;
            k -= 1;
          end;
      end;
    end;
  end;
  if k > letters then
  begin
    for i := 1 to len do
    begin
      if (s[i] <> '*') and (s[i] <> '?') then
      begin
          if (s[i+1] = '*') and (k > -100) then
          begin
            for j := 1 to k - letters + 1 do
            write(s[i]);
            k := -1000;
          end else
          begin
            Write(s[i]);
          end;
      end;
    end;
  end; ReadLn;

end.